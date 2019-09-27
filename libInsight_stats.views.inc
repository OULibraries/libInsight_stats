<?php

/**
 * Implements hook_views_plugins().
 */
function libInsight_stats_views_plugins() {
  $plugin = array();
  $plugin['query']['libInsight_stats_plugin_query'] = array(
    'title' => t('LibInsight Stats Query'),
    'help' => t('LibInsight Stats query object.'),
    'handler' => 'libInsight_stats_plugin_query',
  );
  return $plugin;
}


/**
 * Implements hook_views_data().
 *
 * the actual fields from which the user can choose in the view
 */
function libInsight_stats_views_data() {
  $data = array();

  //Base data
  $data['libInsight_stats']['table']['group'] = t('LibInsight Stats');
  $data['libInsight_stats']['table']['base'] = array(
    'title' => t('LibInsight Stats'),
    'help' => t('Query LibInsight Stats'),
    'query class' => 'libInsight_stats_plugin_query'
  );

  //Fields
  $data['libInsight_stats']['title'] = array(
    'title' => t('Type'),
    'help' => t('The type or category of this dataset'),
    'field' => array(
      'handler' => 'libInsight_stats_handler_field',
    ),
  );
  $data['libInsight_stats']['date'] = array(
    'title' => t('Date'),
    'help' => t('The date of this dataset'),
    'field' => array(
      'handler' => 'libInsight_stats_handler_field',
    ),
  );
  $data['libInsight_stats']['count'] = array(
    'title' => t('Count'),
    'help' => t('The total count of this dataset'),
    'field' => array(
      'handler' => 'libInsight_stats_handler_field',
    ),
  );

  return $data;
}