<?php


/**
 * Checks for unsupported browsers as reported by browscap
 *
 * @return
 *   TRUE if browser is in the blacklist, FALSE otherwise
 */
function template_d7_global_detect_unsupported_browser() {
  
  $browser = browscap_get_browser();
  $browser_unsupported = FALSE;
  
  $ie_compatibility_mode = (stripos($browser['useragent'], 'Trident') === FALSE) ? TRUE : FALSE;
  
  switch($browser['browser']) {
    case 'IE':
      /* don't support IE6 and below */
      if($browser['majorver'] <= 6) {
        $browser_unsupported = TRUE;
      }
    break;
    default:
    break;
  }
  
  return $browser_unsupported;
}

/**
 * Test if we should redirect a browser to the unsupported browsers page
 *
 * This is essentially just a wrapper around template_d7_global_detect_unsupported_browser()
 *
 * @return
 *   TRUE if we need to redirect the user, FALSE otherwise
 */
function template_d7_global_unsupported_browser_redirect_test() {
  
  /* if the browser is unsupported disable cache for every page that isn't the browser warning page */
  $redirect = FALSE;
  $browser_unsupported = template_d7_global_detect_unsupported_browser();
  $uri = request_uri();
  $uri = ltrim($uri, '/');
  
  if($browser_unsupported && $uri != 'browser-unsupported') {
    $redirect = TRUE;
  }
  
  return $redirect;
}

/**
 * Tests for conditions that would result in us wanting to force page caching OFF for this request
 *
 * @return
 *   TRUE if we want to disable the page cache, FALSE if we want to allow caching
 */
function template_d7_global_disable_page_cache_test() {
  
  /* the page cache is generally a good thing.. */
  $disable_page_cache = FALSE;
  
  /* don't cache if we need to redirect a user with an unsupported browser */
  $disable_page_cache = template_d7_global_unsupported_browser_redirect_test();
  
  return $disable_page_cache;
}

/**
 * Implementation of hook_boot()
 */
function template_d7_global_boot() {
  
  /* This will only work if the dynamic_cache module is installed */
  $disable_page_cache = template_d7_global_disable_page_cache_test();
  if($disable_page_cache) {
   $GLOBALS['conf']['cache'] = FALSE; 
  }
    
  return;
}

/**
 * Implementation of hook_init()
 */
function template_d7_global_init() {
  
  /* that's right, we're doing redirects in init instead of boot */
  /* this relies on us forcing the page not to cache in boot */
  $unsupported_browser_redirect_required = template_d7_global_unsupported_browser_redirect_test();
  if($unsupported_browser_redirect_required) {
    drupal_goto('browser-unsupported');
  }
    
  return;
}