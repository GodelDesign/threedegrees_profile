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

          // Archive navigation widget
    $blocks['archiveblock'] = array(
    'info' => t('Archive Block'),
  );

          // Seasonal news header
    $blocks['newsheader'] = array(
    'info' => t('Seasonal News Header'),
  );

              // Menu
    $blocks['menuclock'] = array(
    'info' => t('Menu as block'),
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


/**
 * Renders the archive navigationing block.
 */
function threedegrees_global_block_archiveblock_view() {
  $themepath = drupal_get_path('theme', 'threedegrees_theme');
  $block = array();
  $block['subject'] = '';

  $block_structure = threedegrees_global_taxonomy_build_news_structure();
  krsort($block_structure);

  $content = '';
  foreach($block_structure as $year => $seasons) {
    $season_list = array();
    foreach($seasons as $season) {
      $season_list[] = l($season, 'news/' . $year . '/' . $season);
    }

    $list_params = array(
      'items' => $season_list,
      'title' => $year,
      'type' => 'ul',
      );
    $content .= theme('item_list', $list_params);
  }

  $block['content'] = $content;

  return $block;
}


/**
 * Renders the seasonal news header block.
 */
function threedegrees_global_block_newsheader_view() {
  $themepath = drupal_get_path('theme', 'threedegrees_theme');
  $block = array();
  $block['subject'] = '';

  $season = arg(2);
  $year = arg(1);
  $year = substr($year, -2);

  $content = '<p class=\'seasonalheader\'>' . $season . ' NEWS ' . '\'' . $year . '</p>';

  $block['content'] = $content;

  return $block;
}

/**
 * Renders the  menu block.
 */

function threedegrees_global_block_menuclock_view() {
  $block = array();
  $block['subject'] = '';

  $link_data = array(
    'home' =>'Home',
    'services' => 'Services',
    'projects' => 'Projects',
    'news' => 'News',
    'contactus' => 'Contact Us',
  );

  $markup = array();

  foreach($link_data as $path => $title){
  $title = '<span> ' . $title . '</span>';
  $item_array = array('data' => l($title, $path, array('html' => TRUE)), 'class' => array($path));
    $markup[$path] = $item_array;
  }

  $variables = array(
  'type'=>'ul',
  'items'=> $markup
  );

  $content = theme('item_list', $variables);

  $block['content'] =  $content;

  return $block;
}
