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
  $context->name = 'threedegrees_contactus';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contactus' => 'contactus',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'threedegrees_global-contactpage' => array(
          'module' => 'threedegrees_global',
          'delta' => 'contactpage',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['threedegrees_contactus'] = $context;

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
        'threedegrees_global-welcome' => array(
          'module' => 'threedegrees_global',
          'delta' => 'welcome',
          'region' => 'content',
          'weight' => '-15',
        ),
        'views-homepage_slideshow-block' => array(
          'module' => 'views',
          'delta' => 'homepage_slideshow-block',
          'region' => 'content',
          'weight' => '-14',
        ),
        'threedegrees_global-frontpageblurb' => array(
          'module' => 'threedegrees_global',
          'delta' => 'frontpageblurb',
          'region' => 'content',
          'weight' => '-13',
        ),
        'panels_mini-newsletter_form' => array(
          'module' => 'panels_mini',
          'delta' => 'newsletter_form',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['threedegrees_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'threedegrees_news';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news/*' => 'news/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'panels_mini-newsletter_form' => array(
          'module' => 'panels_mini',
          'delta' => 'newsletter_form',
          'region' => 'content',
          'weight' => '-19',
        ),
        'threedegrees_global-archiveblock' => array(
          'module' => 'threedegrees_global',
          'delta' => 'archiveblock',
          'region' => 'content',
          'weight' => '-10',
        ),
        'threedegrees_global-newsheader' => array(
          'module' => 'threedegrees_global',
          'delta' => 'newsheader',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['threedegrees_news'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'threedegrees_project_node';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['threedegrees_project_node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'threedegrees_projects';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'projects' => 'projects',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-projects-block' => array(
          'module' => 'views',
          'delta' => 'projects-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['threedegrees_projects'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'threedegrees_services';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'services' => 'services',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'threedegrees_global-services' => array(
          'module' => 'threedegrees_global',
          'delta' => 'services',
          'region' => 'content',
          'weight' => '-17',
        ),
        'threedegrees_global-servicesblurb' => array(
          'module' => 'threedegrees_global',
          'delta' => 'servicesblurb',
          'region' => 'content',
          'weight' => '-16',
        ),
        'views-services-block' => array(
          'module' => 'views',
          'delta' => 'services-block',
          'region' => 'content',
          'weight' => '-15',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['threedegrees_services'] = $context;

  return $export;
}
