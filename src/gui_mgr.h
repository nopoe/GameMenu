#ifndef GUI_MGR_H
#define GUI_MGR_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct widget_bounding_box_t
{
	int x, y, width, height;
} widget_bounding_box_t;

typedef void (*widget_click_callback_t)(int button, int mouse_x, int mouse_y, widget_bounding_box_t bb); 

/* Enumerates allowed widget types
 */
typedef enum widget_type_t
{
	BUTTON,
	SLIDER
} widget_type_t;

/* Lists all available ways to define a widget's position
 */
typedef enum coord_type_t
{
	LINE_COORD, //not available for X coords
	NORMALIZED_COORD, //ranges from -1 to 1
	ABSOLUTE_COORD //in pixels
} coord_type_t;

/* 
 */
typedef enum justification_t
{
	RIGHT_JUST,
	LEFT_JUST,
	CENTER_JUST,
	BOTTOM_JUST,
	TOP_JUST
} justification_t;

/*
 */
typedef struct coord_t
{
	int x, y;
	coord_type_t x_coord_type, y_coord_type;
	justification_t x_just, y_just;
} coord_t;

/*
 */
typedef struct widget_t
{
	widget_type_t type;
	char* text;
	int shortcut_key;
	widget_click_callback_t callback1, callback2;
	coord_t layout_info;
} widget_t;

typedef struct widget_list_item_t
{
	struct widget_list_item_t* prev;
	struct widget_list_item_t* next;
	struct widget_t* widget;
} widget_list_item_t;

void gui_mouse_motion_event(int x, int y);
void gui_mouse_button_event(int button, int state, int x, int y);
void gui_keyboard_event(int key, int down);

void gui_draw();

void gui_add_widget(widget_t* widget, coord_t* coord);

void widget_set_text(widget_t* widget, char* text);
void destroy_widget(widget_t* widget);

void setup_gui();
void reset_gui();

#ifdef __cplusplus
}
#endif

#endif
