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
