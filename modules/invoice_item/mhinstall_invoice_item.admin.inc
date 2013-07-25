<?php
/**
 * @file
 * Admin pages for mhinstall_invoice_item.module.
 */

/**
 * Form for adding or editing a mhinstall_invoice_item entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function mhinstall_invoice_item_form($form, &$form_state, $mhinstall_invoice_item) {
  $form['label'] = array(
    '#title' => t('MH Install invoice item ID'),
    '#type' => 'textfield',
    '#default_value' => isset($mhinstall_invoice_item->label) ? $mhinstall_invoice_item->label : '',
    '#description' => t('The label for this MH Install invoice item entity'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('mhinstall_invoice_item', $mhinstall_invoice_item, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($mhinstall_invoice_item->id) ? t('Update MH Install invoice item') : t('Save MH Install invoice item'),
    ),
  );
  return $form;  
}

/**
 * Validation form for mhinstall_invoice_item_form.
 */
function mhinstall_invoice_item_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for mhinstall_invoice_item_form.
 */
function mhinstall_invoice_item_form_submit($form, &$form_state) {
  $mhinstall_invoice_item = entity_ui_form_submit_build_entity($form, $form_state);
  $mhinstall_invoice_item->save();
  drupal_set_message(t('The entity @mhinstall_invoice_item_label has been saved.', array('@mhinstall_invoice_item_label' => $mhinstall_invoice_item->label)));
  $form_state['redirect'] = 'admin/mh-install/data-types/mhinstall_invoice_item';
}