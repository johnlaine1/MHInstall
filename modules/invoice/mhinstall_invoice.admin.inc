<?php
/**
 * @file
 * Admin pages for mhinstall_invoice.module.
 */

/**
 * Form for adding or editing a mhinstall_invoice entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function mhinstall_invoice_form($form, &$form_state, $mhinstall_invoice) {
  $form['label'] = array(
    '#title' => t('MH Install Invoice ID'),
    '#type' => 'textfield',
    '#default_value' => isset($mhinstall_invoice->label) ? $mhinstall_invoice->label : '',
    '#description' => t('The label for this MH Install Invoice entity'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('mhinstall_invoice', $mhinstall_invoice, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($mhinstall_invoice->id) ? t('Update MH Install Invoice') : t('Save MH Install Invoice'),
    ),
  );
  return $form;  
}

/**
 * Validation form for mhinstall_invoice_form.
 */
function mhinstall_invoice_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for mhinstall_invoice_form.
 */
function mhinstall_invoice_form_submit($form, &$form_state) {
  $mhinstall_invoice = entity_ui_form_submit_build_entity($form, $form_state);
  $mhinstall_invoice->save();
  drupal_set_message(t('The entity @mhinstall_invoice_label has been saved.', array('@mhinstall_invoice_label' => $mhinstall_invoice->label)));
  $form_state['redirect'] = 'admin/mh-install/data-types/mhinstall_invoice';
}