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
