/**
 * @file
 *
 * fgui application structure
 *
 * Every fgui program (that wants to use widgets that accept user input) needs
 * to create exactly one application structure. The application structure is
 * the parent of all widgets and knows what widget has focus. It also
 * dispatches input events to the widget that has focus.
 */

#ifndef FGUI_APPLICATION_H
#define FGUI_APPLICATION_H

#include <stddef.h>

#include "fgui_widget.h"

struct fgui_application {
	struct fgui_widget *focus_widget;

	int current_widget;
	// TODO: linked list?
	struct fgui_widget *children[FGUI_MAX_CHILDREN];

	size_t num_children;
};


void fgui_application_init(struct fgui_application *app);
void fgui_application_process_event(struct fgui_application *app, struct fgui_event *event);

#endif /* FGUI_APPLICATION_H */
