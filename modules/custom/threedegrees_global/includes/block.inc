<?php
/**
 * @file
 * Integrate threedegrees.module with block.module
 */

/**
 * Implements hook_block_info().
 */
function threedegrees_global_block_info() {
  $blocks = array();

  // Welcome text for the front page.
  $blocks['welcome'] = array(
    'info' => t('Welcome'),
  );

  // Front page blurb
    $blocks['frontpageblurb'] = array(
    'info' => t('Front Page Blurb'),
  );

      // Services heading
    $blocks['services'] = array(
    'info' => t('Services Heading'),
  );

      // Services blurb
    $blocks['servicesblurb'] = array(
    'info' => t('Services Blurb'),
  );

      // Contact Page
    $blocks['contactpage'] = array(
    'info' => t('Contact Details'),
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function threedegrees_global_block_view($delta = ''){
  $ret = '';

  $function = 'threedegrees_global_block_' . $delta . '_view';
  if(function_exists($function)) {
    $ret = $function();
  }

  return $ret;
}

/**
 * Renders the welcome block.
 */
function threedegrees_global_block_welcome_view() {
  $block = array();
  $block['subject'] = '';

  $content = '';
  $content .= '<h2>Welcome</h2>';

  $block['content'] = $content;

  return $block;
}

/**
 * Renders the front page blurb block.
 */
function threedegrees_global_block_frontpageblurb_view() {
  $block = array();
  $block['subject'] = '';

  $content = '';
  $content .= '<div class="frontpageblurb"><p> 3 Degrees Marketing is a Melbourne based marketing agency, with a strong brand reputation and an enviable list of clients across Australia and New Zealand.</p><p>From sponsorship and commercial rights management to company rebrands, communication strategies, PR, graphic design and event management, our team utilises a strong network of contacts to provide exceptional results.</p></div>';

  $block['content'] = $content;

  return $block;
}

/**
 * Renders the servcices title block.
 */
function threedegrees_global_block_services_view() {
  $block = array();
  $block['subject'] = '';

  $content = '';
  $content .= '<h2>Our Services</h2>';

  $block['content'] = $content;

  return $block;
}

/**
 * Renders the front page blurb block.
 */
function threedegrees_global_block_servicesblurb_view() {
  $block = array();
  $block['subject'] = '';

  $content = '';
  $content .= '<div class="servicesblurb"><p> From sponsorship and commercial rights management to company rebrands, communication strategies, PR, graphic design and event management, our team utilises a strong network of contacts to provide exceptional results.</p></div>';

  $block['content'] = $content;

  return $block;
}



/**
 * Renders the contact page block.
 */
function threedegrees_global_block_contactpage_view() {
  $themepath = drupal_get_path('theme', 'threedegrees_theme');
  $block = array();
  $block['subject'] = '';

  $content = '';
  $content .= '<div class="contactustitle"><p>Contact Us</p></div>
  <img class="map" src="/' . $themepath . '/css/img/map.png"></img>
  <div class="contactdetails"><p class="contactbold">Need to get in touch with us? Call, fax, email or even write a letter. <br /> We look forward to hearing from you.</p>
   <p>level 1 454a Church st, Richmond<br />
      PO BOX 4233, Richmond East, VIC 3121<br /><br />
      Ph: 03 8416 5999 <br/>
      Fax: 03 9421 2966<br/>
      E: info@3dm.com.au</div>';

  $block['content'] = $content;

  return $block;
}
