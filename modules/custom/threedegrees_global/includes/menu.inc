<?php

/**
 * Implements hook_menu()
 */
function threedegrees_global_menu() {
  $items = array();

  /* Blank placeholder for the front page */
  $items['home'] = array(
    'title' => 'Home', // Will likely be overriden by page_title module
    'description' => 'The front page',
    'page callback' => 'threedegrees_global_blank_page',
    'access callback' => TRUE, // Assume most use-cases require all users to see the front page
    'type' => MENU_CALLBACK,
    'file' => 'includes/threedegrees_global.pages.inc',
  );

    $items['services'] = array(
    'title' => 'Services', // Will likely be overriden by page_title module
    'description' => 'Services',
    'page callback' => 'threedegrees_global_blank_page',
    'access callback' => TRUE, // Assume most use-cases require all users to see the front page
    'type' => MENU_CALLBACK,
    'file' => 'includes/threedegrees_global.pages.inc',
  );

      $items['projects'] = array(
    'title' => 'Projects', // Will likely be overriden by page_title module
    'description' => 'Projects',
    'page callback' => 'threedegrees_global_blank_page',
    'access callback' => TRUE, // Assume most use-cases require all users to see the front page
    'type' => MENU_CALLBACK,
    'file' => 'includes/threedegrees_global.pages.inc',
  );

        $items['news'] = array(
    'title' => 'News', // Will likely be overriden by page_title module
    'description' => 'News',
    'page callback' => 'threedegrees_global_blank_page',
    'access callback' => TRUE, // Assume most use-cases require all users to see the front page
    'type' => MENU_CALLBACK,
    'file' => 'includes/threedegrees_global.pages.inc',
  );

          $items['contactus'] = array(
    'title' => 'Contact Us', // Will likely be overriden by page_title module
    'description' => 'Contact Us',
    'page callback' => 'threedegrees_global_blank_page',
    'access callback' => TRUE, // Assume most use-cases require all users to see the front page
    'type' => MENU_CALLBACK,
    'file' => 'includes/threedegrees_global.pages.inc',
  );

/* Page to redirect to for incompatible browsers */
 $items['browser-unsupported'] = array(
  'title' => 'Your browser is unsupported',
  'description' => 'Browser unsupported page',
  'page callback' => 'threedegrees_global_incompatible_browser_page',
  'access callback' => TRUE, // Everyone with a shit browser needs to see this
  'type' => MENU_CALLBACK,
  'file' => 'includes/threedegrees_global.pages.inc',
  );

  return $items;
}

/**
 * Implements hook_menu_alter()
 */
function threedegrees_global_menu_alter(&$items) {

  /* Production Check will complain about this as a security risk if we leave it set */
  unset($items['node']);

}
