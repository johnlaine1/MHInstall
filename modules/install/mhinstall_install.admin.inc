<?php
/**
 * @file
 * Admin pages for mhinstall_install.module.
 */

/**
 * Form for adding or editing a mhinstall_install entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function mhinstall_install_form($form, &$form_state, $mhinstall_install) {
  $form['label'] = array(
    '#title' => t('MH Install ID'),
    '#type' => 'textfield',
    '#default_value' => isset($mhinstall_install->label) ? $mhinstall_install->label : '',
    '#description' => t('The label for this MH Install'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('mhinstall_install', $mhinstall_install, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($mhinstall_install->id) ? t('Update MH Install') : t('Save MH Install'),
    ),
  );
  return $form;  
}

/**
 * Validation form for mhinstall_install_form.
 */
function mhinstall_install_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for mhinstall_install_form.
 */
function mhinstall_install_form_submit($form, &$form_state) {
  $mhinstall_install = entity_ui_form_submit_build_entity($form, $form_state);
  $mhinstall_install->save();
  drupal_set_message(t('The entity @mhinstall_install_label has been saved.', array('@mhinstall_install_label' => $mhinstall_install->label)));
  $form_state['redirect'] = 'admin/structure/mhinstall_install';
}