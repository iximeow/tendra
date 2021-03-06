# Copyright 2002-2011, The TenDRA Project.
# Copyright 1995-1996, IXI Ltd.
#
# See doc/copyright/ for the full copyright terms.


%%
#ifndef __MOTIF_P_HEADERS
#error Unexpected access to Motif P headers
#endif
%%

+USE "c/c89", "ctype.h.ts";

+ENUM XmTextStatus := { 

	EditDone,
	EditError,
	EditReject
};

+ENUM XmTextScanDirection := { 

	XmsdLeft,
	XmsdRight
};

+FIELD (struct) _XmSourceDataRec := { 

	XmTextSource		source;
	char			*ptr;
	char			*value;
	char			*gap_start;
	char			*gap_end;
	XmTextWidget		*widgets;
	int			length;
	int			maxlength;
	int			old_length;
	int			numwidgets;
	int			maxallowed;
	Boolean			hasselection;
	Boolean			editable;
	XmTextPosition		left;
	XmTextPosition		right;
	Time			prim_time;
};

+TYPEDEF _XmSourceDataRec XmSourceDataRec;
+TYPEDEF _XmSourceDataRec *XmSourceData;


+TYPEDEF void (*AddWidgetProc)(XmTextSource, XmTextWidget);
+TYPEDEF int (*CountLinesProc)(XmTextSource, XmTextPosition, int);
+TYPEDEF void (*RemoveWidgetProc)(XmTextSource, XmTextWidget);
+TYPEDEF XmTextPosition (*ReadProc)(XmTextSource, XmTextPosition, XmTextPosition, XmTextBlock);
+TYPEDEF XmTextStatus (*ReplaceProc)(XmTextSource, XEvent *, XmTextPosition, XmTextPosition, XmTextBlock);
+TYPEDEF XmTextPosition (*ScanProc)(XmTextSource, XmTextPosition, XmTextScanType, XmTextScanDirection, int, Boolean);
+TYPEDEF Boolean (*GetSelectionProc)(XmTextSource, XmTextPosition *, XmTextPosition *);
+TYPEDEF void (*SetSelectionProc)(XmTextSource, XmTextPosition, XmTextPosition, Time);

+FIELD (struct) _XmTextSourceRec :={ 

	XmSourceDataRec		*data;
	AddWidgetProc		AddWidget;
	CountLinesProc		CountLines;
	RemoveWidgetProc	RemoveWidget;
	ReadProc		ReadSource;
	ReplaceProc		Replace;
	ScanProc		Scan;
	GetSelectionProc	GetSelection;
	SetSelectionProc	SetSelection;
};

 


