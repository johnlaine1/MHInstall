<?php
/**
 * @file
 * Admin pages for mhinstall_community.module.
 */

/**
 * Form for adding or editing a mhinstall_community entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function mhinstall_community_form($form, &$form_state, $mhinstall_community) {
  $form['label'] = array(
    '#title' => t('MH Install Community ID'),
    '#type' => 'textfield',
    '#default_value' => isset($mhinstall_community->label) ? $mhinstall_community->label : '',
    '#description' => t('The label for this MH Install Community entity'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('mhinstall_community', $mhinstall_community, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($mhinstall_community->id) ? t('Update MH Install Community') : t('Save MH Install Community'),
    ),
  );
  return $form;  
}

/**
 * Validation form for mhinstall_community_form.
 */
function mhinstall_community_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for mhinstall_community_form.
 */
function mhinstall_community_form_submit($form, &$form_state) {
  $mhinstall_community = entity_ui_form_submit_build_entity($form, $form_state);
  $mhinstall_community->save();
  drupal_set_message(t('The entity @mhinstall_community_label has been saved.', array('@mhinstall_community_label' => $mhinstall_community->label)));
  $form_state['redirect'] = 'admin/structure/mhinstall_community';
}