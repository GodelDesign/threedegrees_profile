<?php
/**
 * @file
 * threedegrees_global.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function threedegrees_global_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'threedegrees_global';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'panels_mini-header_logo' => array(
          'module' => 'panels_mini',
          'delta' => 'header_logo',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'panels_mini-menu' => array(
          'module' => 'panels_mini',
          'delta' => 'menu',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'panels_mini-ubiquitous_footer' => array(
          'module' => 'panels_mini',
          'delta' => 'ubiquitous_footer',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['threedegrees_global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'threedegrees_homepage';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'home' => 'home',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'panels_mini-welcome' => array(
          'module' => 'panels_mini',
          'delta' => 'welcome',
          'region' => 'content',
          'weight' => '-14',
        ),
        'views-homepage_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'homepage_slideshow-block',
          'region' => 'content',
          'weight' => '-13',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['threedegrees_homepage'] = $context;

  return $export;
}
