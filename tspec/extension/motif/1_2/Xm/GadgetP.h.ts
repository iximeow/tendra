# Copyright 2002-2011, The TenDRA Project.
# Copyright 1995-1996, IXI Ltd.
#
# See doc/copyright/ for the full copyright terms.


%%
#ifndef __MOTIF_P_HEADERS
#error Unexpected access to Motif P headers
#endif
%%

%%
#define GADGET
%%

+USE "motif/1_2", "Xm/XmP.h.ts";


+CONST int XmNO_EVENT;
+CONST int XmENTER_EVENT;
+CONST int XmLEAVE_EVENT;
+CONST int XmFOCUS_IN_EVENT;
+CONST int XmFOCUS_OUT_EVENT;
+CONST int XmMOTION_EVENT;
+CONST int XmARM_EVENT;
+CONST int XmACTIVATE_EVENT;
+CONST int XmHELP_EVENT;
+CONST int XmKEY_EVENT;
+CONST int XmMULTI_ARM_EVENT;
+CONST int XmMULTI_ACTIVATE_EVENT;
+CONST int XmBDRAG_EVENT;
+CONST int XmALL_EVENT;

+MACRO Dimension G_ShadowThickness( XmGadget ); 
+MACRO Dimension G_HighlightThickness( XmGadget ); 

+CONST long XmGadgetClassExtVersion;

+TYPE (struct) _XmGadgetCache;

+FIELD (struct) _XmGadgetCache := { 

	_XmGadgetCache	*next;
	_XmGadgetCache	*prev;
	int			ref_count;
};

+TYPEDEF _XmGadgetCache XmGadgetCache;
+TYPEDEF _XmGadgetCache * XmGadgetCachePtr;

+FIELD (struct) XmCacheClassPart := { 

	XmGadgetCache		cache_head;
	XmCacheCopyProc		cache_copy;
	XmGadgetCacheProc	cache_delete;
	XmCacheCompareProc	cache_compare;
};

+TYPEDEF XmCacheClassPart *XmCacheClassPartPtr;

+FIELD (struct) _XmGadgetCacheRef := {

	XmGadgetCache		cache;
	XtArgVal		data;
};

+TYPEDEF _XmGadgetCacheRef XmGadgetCacheRef;
+TYPEDEF _XmGadgetCacheRef *XmGadgetCacheRefPtr;

+FIELD (struct) _XmGadgetClassExtRec := { 

	XtPointer		next_extension;
	XrmQuark		record_type;
	long			version;
	Cardinal		record_size;
	XmWidgetBaselineProc	widget_baseline;
	XmWidgetDisplayRectProc	widget_display_rect;
};

+TYPEDEF _XmGadgetClassExtRec XmGadgetClassExtRec;
+TYPEDEF _XmGadgetClassExtRec *XmGadgetClassExt;

+MACRO XmGadgetClassExt * GCEPTR( WidgetClass ); 
+MACRO XmGadgetClassExt * _XmGetGadgetClassExtPtr(WidgetClass, XrmQuark); 

+FIELD (struct) _XmGadgetClassPart := {

	XtWidgetProc		border_highlight;
	XtWidgetProc		border_unhighlight;
	XtActionProc		arm_and_activate;
	XmWidgetDispatchProc	input_dispatch;
	XmVisualChangeProc	visual_change;
	XmSyntheticResource	*syn_resources;
	int			num_syn_resources;
	XmCacheClassPartPtr	cache_part;
	XtPointer		extension;
};

+TYPEDEF _XmGadgetClassPart XmGadgetClassPart;

+FIELD struct _XmGadgetClassRec := {

	RectObjClassPart	rect_class;
	XmGadgetClassPart	gadget_class;
}; 

+TYPEDEF struct _XmGadgetClassRec XmGadgetClassRec;

+EXP lvalue XmGadgetClassRec xmGadgetClassRec;

+FIELD (struct) XmGadgetPart := {

	Dimension		shadow_thickness;
	Dimension		highlight_thickness;

	XtCallbackList		help_callback;
	XtPointer		user_data;

	Boolean			traversal_on;
	Boolean			highlight_on_enter;
	Boolean			have_traversal;

	unsigned char		unit_type;
	XmNavigationType	navigation_type;

	Boolean			highlight_drawn;
	Boolean			highlighted;
	Boolean			visible;

	Mask			event_mask;
};


+FIELD struct _XmGadgetRec := { 

	ObjectPart		object;
	RectObjPart		rectangle;
	XmGadgetPart		gadget;
};

+TYPEDEF struct _XmGadgetRec XmGadgetRec;

+FUNC void _XmBuildGadgetResources( WidgetClass );
	

