/* Amil - assembleur miniature pour l'informatique de licence
 *        (Toy assembly langage interpreter)
 *
 * Copyright 2008, 2009 Pierre Boudes
 *
 * This file is part of Amil.
 *
 * Amil is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Amil is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Amil.  If not, see <http://www.gnu.org/licenses/>.
 */
/* -*- coding: utf-8 -*- */
/* ig.c */
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "ig.h"
#include "controleur.h"


#define COLS_REG 4
ig_t ig; 

/* Remarque : on n'alloue pas dynamiquement l'ig, c'est inutile : il n'y en a qu'une instance qui existe toujours. */


void
myperror(char *s)
{
  ig_maj_console(s);
}

void 
ig_faire_fenetre_principale()
{
  GtkWidget *reg_zones[NOMBRE_REGISTRES];
  GtkWidget *proc_zone;
  GtkWidget *cp_zone;
  GtkWidget *horloge_zone;
  GtkWidget *console_zone;
  GtkWidget *console_scroll;
  GtkWidget *vboxcp;
  GtkWidget *bouton_raz_proc;
  GtkWidget *bouton_raz_cp;
  GtkWidget *bouton_raz_cycles;
  GtkWidget *vboxreg[NOMBRE_REGISTRES / COLS_REG];
  GtkWidget *hbox_proc;
  GtkWidget *hboxboutons;
  GtkWidget *bouton_charger;
  GtkWidget *bouton_enregistrer;
  GtkWidget *bouton_voir;
  GtkWidget *bouton_pap;
  GtkWidget *bouton_exe;
  GtkWidget *bouton_stop;
  GtkWidget *bouton_quit;
  GtkWidget *vboxglobale;
  GdkColor color;

  int i, j;
  char s[16];

  /** La vue du processeur **/

  proc_zone = gtk_frame_new("Processeur");

  /* Les registres */
  for (i = 0; i < NOMBRE_REGISTRES; i++) {
    sprintf(s, "registre %2d", i);
    reg_zones[i] = gtk_frame_new(s);
    ig.reg[i] = gtk_label_new("?");
    gtk_container_add(GTK_CONTAINER(reg_zones[i]), ig.reg[i]);
  }

  /* Le CP */
  cp_zone = gtk_frame_new("CP");
  ig.cp = gtk_label_new("0");
  gtk_container_add(GTK_CONTAINER(cp_zone), ig.cp);
  
  /* L'horloge (cycles) */
  horloge_zone = gtk_frame_new("Cycles d'horloge");
  ig.horloge = gtk_label_new("0");
  gtk_container_add(GTK_CONTAINER(horloge_zone), ig.horloge);

  /* Les remises à zéro */
  bouton_raz_proc = gtk_button_new_with_mnemonic("RàZ processeur");
  bouton_raz_cp = gtk_button_new_with_mnemonic("RàZ CP");
  bouton_raz_cycles = gtk_button_new_with_mnemonic("RàZ horloge");
 
  /** La console **/
  console_zone = gtk_frame_new("Console");
  console_scroll = gtk_scrolled_window_new(NULL, NULL);
  ig.console = gtk_text_view_new();
  ig.buffer_console = gtk_text_view_get_buffer (GTK_TEXT_VIEW (ig.console));
  gtk_container_add(GTK_CONTAINER(console_zone), console_scroll);
  gtk_container_add(GTK_CONTAINER(console_scroll), ig.console);
  gtk_text_view_set_left_margin(GTK_TEXT_VIEW(ig.console), 10);
  gtk_text_view_set_editable(GTK_TEXT_VIEW (ig.console), 0);
  gdk_color_parse ("green", &color);
  gtk_widget_modify_text (ig.console, GTK_STATE_NORMAL, &color);
  gdk_color_parse ("black", &color);
  gtk_widget_modify_base (ig.console, GTK_STATE_NORMAL, &color);
  gtk_text_buffer_set_text(ig.buffer_console, "Pas de programme\n", -1);
  

  /* Quelques boutons */
  bouton_charger = gtk_button_new_with_mnemonic("_Charger...");
  bouton_enregistrer = gtk_button_new_with_mnemonic("_Enregistrer sous...");
  bouton_voir = gtk_button_new_with_mnemonic("_Voir la mémoire");
  bouton_pap = gtk_button_new_with_mnemonic("_Pas à pas");
  bouton_stop = gtk_button_new_from_stock(GTK_STOCK_STOP);
  bouton_exe = gtk_button_new_from_stock(GTK_STOCK_EXECUTE);
  bouton_quit = gtk_button_new_from_stock(GTK_STOCK_QUIT);

  /* Les boites */
  hbox_proc = gtk_hbox_new(FALSE, 20);
  vboxcp = gtk_vbox_new(TRUE, 2);
  hboxboutons = gtk_hbox_new(FALSE, 0);
  vboxglobale = gtk_vbox_new(FALSE, 20);
  for (j = 0; j < NOMBRE_REGISTRES / COLS_REG; j++) {
    vboxreg[j] = gtk_vbox_new(TRUE, 5);
  }

  /*** Organisation à l'ecran ****/

  /* Rappels sur les box : 
     ...box_new(gboolean homogeneous, gint spacing);

homogeneous :	TRUE if all children are to be given equal space allotments.
spacing :	the number of pixels to place by default between children.)

    ...box_pack_start(..., gboolean expand, gboolean fill, guint padding));

expand :	TRUE if the new child is to be given extra space allocated to box. The extra space will be divided evenly between all children of box that use this option.

fill :	TRUE if space given to child by the expand option is actually allocated to child, rather than just padding it. This parameter has no effect if expand is set to FALSE. A child is always allocated the full height of a GtkHBox and the full width of a GtkVBox. This option affects the other dimension.
  */

  /* En haut, une ligne avec boutons */
  gtk_box_pack_start(GTK_BOX(vboxglobale), hboxboutons, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hboxboutons), bouton_charger, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hboxboutons), bouton_enregistrer, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hboxboutons), bouton_voir, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hboxboutons), bouton_pap, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hboxboutons), bouton_exe, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hboxboutons), bouton_stop, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hboxboutons), bouton_quit, TRUE, TRUE, 0);
 
  /*En dessous, le processeur (avec CP, horloge, RàZ et la matrice des
    registres) */

  gtk_container_add(GTK_CONTAINER(proc_zone), hbox_proc);
  gtk_box_pack_start(GTK_BOX(vboxglobale), proc_zone, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vboxcp), bouton_raz_proc, FALSE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(vboxcp), cp_zone, TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(vboxcp), bouton_raz_cp, FALSE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(vboxcp), horloge_zone, TRUE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(vboxcp), bouton_raz_cycles, FALSE, TRUE, 5);
  gtk_box_pack_start(GTK_BOX(hbox_proc), vboxcp, TRUE, TRUE, 5);

  for (j = 0; j < NOMBRE_REGISTRES / COLS_REG; j++) {
    gtk_box_pack_start(GTK_BOX(hbox_proc), vboxreg[j], TRUE, TRUE, 5);
  }

  for (i = 0; i < NOMBRE_REGISTRES; i++) {
    j = i / COLS_REG;                           
    gtk_box_pack_start(GTK_BOX(vboxreg[j]), reg_zones[i], TRUE, TRUE, 0);
  }

  /*En bas, la console */
  gtk_box_pack_start(GTK_BOX(vboxglobale), console_zone, TRUE, TRUE, 0);  


  /* La fenetre */
  ig.fenetre_principale = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(ig.fenetre_principale), 
                              640, 
                              480);
  gtk_window_set_title(GTK_WINDOW(ig.fenetre_principale), "Machine AMIL");
  gtk_container_add(GTK_CONTAINER(ig.fenetre_principale), vboxglobale);

  gtk_widget_show_all(ig.fenetre_principale);

  /**** Signaux ****/

  /* RàZ */
  g_signal_connect(bouton_raz_proc, "clicked", 
		   G_CALLBACK(ig_raz_proc), &ig);
  g_signal_connect(bouton_raz_cp, "clicked", 
		   G_CALLBACK(ig_raz_cp), &ig);
  g_signal_connect(bouton_raz_cycles, "clicked", 
		   G_CALLBACK(ig_raz_cycles), &ig);

  /* Charger */
  ig.dialogue_charger =
    gtk_file_chooser_dialog_new("Charger un programme",
				GTK_WINDOW(ig.fenetre_principale),
				GTK_FILE_CHOOSER_ACTION_OPEN,
				GTK_STOCK_CANCEL,
				GTK_RESPONSE_CANCEL,
				GTK_STOCK_OPEN,
				GTK_RESPONSE_ACCEPT,
				NULL);


  g_signal_connect(bouton_charger, "clicked", 
		   G_CALLBACK(ig_charger), ig.dialogue_charger);

  /* Enregistrer */
  ig.dialogue_enregistrer =
    gtk_file_chooser_dialog_new("Enregistrer le programme",
				GTK_WINDOW(ig.fenetre_principale),
				GTK_FILE_CHOOSER_ACTION_SAVE,
				GTK_STOCK_CANCEL,
				GTK_RESPONSE_CANCEL,
				GTK_STOCK_SAVE,
				GTK_RESPONSE_ACCEPT,
				NULL);
  g_signal_connect(bouton_enregistrer, "clicked", 
		   G_CALLBACK(ig_dump), ig.dialogue_enregistrer);
  g_signal_connect(bouton_voir, "clicked",
		   G_CALLBACK(ig_voir_memoire), &ig);

  /* Voir memoire */
  g_signal_connect(bouton_voir, "clicked", 
		   G_CALLBACK(ig_voir_memoire), &ig);


  /* Execution */
  g_signal_connect(bouton_pap, "clicked", 
		   G_CALLBACK(ig_pas_a_pas), &ig);
  g_signal_connect(bouton_exe, "clicked", 
		   G_CALLBACK(ig_executer), &ig);
  g_signal_connect(bouton_stop, "clicked", 
		   G_CALLBACK(ig_stop), &ig);

  /**** Quitter ****/
  ig.dialogue_quitter = 
    gtk_dialog_new_with_buttons("Quitter AMIL ?",
				GTK_WINDOW(ig.fenetre_principale),
				GTK_DIALOG_MODAL,
				GTK_STOCK_CANCEL,
				GTK_RESPONSE_CANCEL,
				GTK_STOCK_OK,
				GTK_RESPONSE_OK,
				NULL);

  g_signal_connect(ig.fenetre_principale, "destroy", 
		   G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(bouton_quit, "clicked", 
		   G_CALLBACK(ig_quitter), ig.dialogue_quitter);

}


void
ig_maj_registre(mot_t x, registre_t i)
{
  gchar s[16];
  GdkColor color;

  sprintf(s, "%hd", x);
  gtk_label_set_label(GTK_LABEL(ig.reg[i]), s);
  gdk_color_parse ("yellow", &color);
  gtk_widget_modify_bg (ig.reg[i]->parent, GTK_STATE_NORMAL, &color);
}

void
ig_maj_cp(mot_t x)
{
  gchar s[16];
  sprintf(s, "%hd", x);
  gtk_label_set_label(GTK_LABEL(ig.cp), s);
}

void
ig_maj_console(gchar *s)
{
  GtkTextIter end;
  gtk_text_buffer_get_end_iter(ig.buffer_console, &end);
  gtk_text_buffer_insert(ig.buffer_console, &end, s, -1);
  gtk_text_buffer_get_end_iter(ig.buffer_console, &end);
  gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(ig.console), 
			       &end, 0.0, TRUE, 0.0, 1.0);
}

void
ig_raz_registres()
{
  int i;
  for (i = 0; i < NOMBRE_REGISTRES; i++) {
    gtk_label_set_label(GTK_LABEL(ig.reg[i]), "?"); 
  }
}

void
ig_maj_cycles(int x)
{
  gchar s[16];
  sprintf(s, "%d", x);
  gtk_label_set_label(GTK_LABEL(ig.horloge), s);
  ig.cycles = x;
}

void
ig_inc_cycles()
{
  ig_maj_cycles(++ig.cycles);
}

void
ig_faire_fenetre_memoire()
{
  GtkWidget *memoire_scroll;
  GdkColor color;
  PangoFontDescription *font_desc;

  /* Une zone de texte avec des ascenceurs */
  memoire_scroll = gtk_scrolled_window_new(NULL, NULL);
  ig.memoire = gtk_text_view_new();
  ig.memoire_buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (ig.memoire));
  gtk_container_add(GTK_CONTAINER(memoire_scroll), ig.memoire);
  gtk_text_view_set_left_margin(GTK_TEXT_VIEW(ig.memoire), 10);
  gtk_text_view_set_editable(GTK_TEXT_VIEW (ig.memoire), 0);
  gdk_color_parse ("black", &color);
  gtk_widget_modify_text (ig.memoire, GTK_STATE_NORMAL, &color);
  gdk_color_parse ("lightgray", &color);
  font_desc = pango_font_description_from_string ("Mono bold 12");
  gtk_widget_modify_font (ig.memoire, font_desc);
  pango_font_description_free (font_desc);

  gtk_widget_modify_base (ig.memoire, GTK_STATE_NORMAL, &color);
  gtk_text_buffer_set_text(ig.memoire_buffer, "Pas de programme\n", -1);

  /* La fenetre */
  ig.fenetre_memoire = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(ig.fenetre_memoire), 
                              240, 
                              480);
  gtk_window_set_title(GTK_WINDOW(ig.fenetre_memoire), 
		       "AMIL : mémoire");
  gtk_container_add(GTK_CONTAINER(ig.fenetre_memoire), memoire_scroll);

  gtk_widget_hide_all(ig.fenetre_memoire);

  g_signal_connect(ig.fenetre_memoire, "destroy", 
		   G_CALLBACK(ig_masquer_memoire), NULL);

  ig.tagg  = gtk_text_buffer_create_tag (ig.memoire_buffer, 
					 "green_background",
					 "background", 
					 "green", NULL);

  ig.tagy = gtk_text_buffer_create_tag (ig.memoire_buffer, 
					"yellow_background",
					"background", 
					"yellow", NULL);
}

void
ig_maj_memoire(instruction_t *mem, int len, int l, int cp, int flag_num)
{
  GtkTextIter debut;
  GtkTextIter fin;
  int i;
  gchar s[129];
  size_t sz;
  sz = 129;

  if (!GTK_IS_WIDGET(ig.fenetre_memoire)) {
    return;
  }

  /* RaZ du buffer texte */
  gtk_text_buffer_set_text(ig.memoire_buffer, "", -1);

  /* Affichage ligne à ligne */
  for (i = 1; i < len; i++) {
    /* Doit on mettre les numéros de ligne  ?*/
    if (flag_num) {
      if (i != cp) {
	sprintf(s, "%5d  ", i);
      } else {
	sprintf(s, "%5d->", i);
      }
      gtk_text_buffer_insert_at_cursor(ig.memoire_buffer, s, -1);
    }
    if (!instruction2texte(mem + i, s, sz)) {
      gtk_text_buffer_insert_at_cursor(ig.memoire_buffer, "?\n", -1);
    }
    else {
      gtk_text_buffer_insert_at_cursor(ig.memoire_buffer, s, -1);
    }
  }

  /* Mettre en valeur l'instruction ligne 'l' */

  if (l) {  
    gtk_text_buffer_get_iter_at_line_offset(ig.memoire_buffer, 
					    &debut, l - 1,
					    flag_num?6:0);
    gtk_text_buffer_get_iter_at_line(ig.memoire_buffer, &fin, l);
    gtk_text_buffer_apply_tag_by_name (ig.memoire_buffer, 
				       "green_background",
				       &debut, &fin);
  }
}


void
ig_enlumine_memoire(int l, int flag_num)
{
  GtkTextIter debut;
  GtkTextIter fin;

  /* Mettre en valeur l'instruction ligne 'l' */

  if (l) {  
    gtk_text_buffer_get_iter_at_line_offset(ig.memoire_buffer, 
					    &debut, l - 1,
					    flag_num?6:0);
    gtk_text_buffer_get_iter_at_line(ig.memoire_buffer, &fin, l);
    gtk_text_buffer_apply_tag_by_name (ig.memoire_buffer, 
				       "yellow_background",
				       &debut, &fin);
  }  
}


void
ig_ouvrir_fenetre_memoire()
{
  if (GTK_IS_WIDGET(ig.fenetre_memoire)) {  
    gtk_widget_show_all(ig.fenetre_memoire);
    gtk_window_present (GTK_WINDOW(ig.fenetre_memoire));
  } else {
    ig_faire_fenetre_memoire();
  }

}

void
ig_fermer_fenetre_memoire()
{
  gtk_widget_hide_all(ig.fenetre_memoire);
}

void
ig_no_emph_proc()
{
  GdkColor color;
  int i;
  gdk_color_parse ("white", &color);
  gtk_widget_modify_bg (ig.cp->parent, GTK_STATE_NORMAL, &color);
  for (i = 0; i < NOMBRE_REGISTRES; i++) {
    gtk_widget_modify_bg (ig.reg[i]->parent, GTK_STATE_NORMAL, &color);
  }
}

void
ig_emph_cp()
{
  GdkColor color;
  gdk_color_parse ("yellow", &color);
  gtk_widget_modify_bg (ig.cp->parent, GTK_STATE_NORMAL, &color);
}
