<?php
/**
 * @file
 * threedegrees_global.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function threedegrees_global_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'homepage_slideshow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'homepage_slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Slideshow Images */
  $handler->display->display_options['fields']['field_slideshow_images']['id'] = 'field_slideshow_images';
  $handler->display->display_options['fields']['field_slideshow_images']['table'] = 'field_data_field_slideshow_images';
  $handler->display->display_options['fields']['field_slideshow_images']['field'] = 'field_slideshow_images';
  $handler->display->display_options['fields']['field_slideshow_images']['label'] = '';
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_slideshow_images']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_slideshow_images']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_slideshow_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_slideshow_images']['settings'] = array(
    'image_style' => 'slideshow',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_slideshow_images']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_slideshow_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_slideshow_images']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_slideshow_images']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_slideshow_images']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['homepage_slideshow'] = $view;

  return $export;
}
