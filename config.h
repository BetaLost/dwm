#include <X11/XF86keysym.h>
#include "/home/chief/.cache/wal/colors-wal-dwm.h"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 15;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 5;        /* horizontal padding for statusbar */
static const int vertpadbar         = 16;        /* vertical padding for statusbar */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const char *fonts[]          = { "JetBrains Mono Nerd Font:size=12:style=bold" };
static const char dmenufont[]       = "JetBrains Mono Nerd Font:size=14";

/* tagging */
// static const char *tags[] = { "", "", "", "", "" };
static const char *tags[] = { "󰎤", "󰎧", "󰎪", "󰎭", "󰎱" }; // "󰎳", "󰎶", "󰎹", "󰎼"

static const unsigned int ulinepad = 5; /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke = 2; /* thickness / height of the underline */
static const unsigned int ulinevoffset = 0; /* how far above the bottom of the bar the line should appear */
static const int ulineall = 0; /* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class             instance    title       tags mask     iscentered     isfloating   monitor */
	{ "floatst",         NULL,       NULL,       0,            1,             1,           -1 },
	{ "kdeconnect.app",  NULL,       NULL,       0,            1,             1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
};

/* Status bar script */
#define STATUSBAR "dwmbar.sh"

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-i", "-c", "-l", "10", "-p", "App Launcher", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *powermenucmd[] = { "pkill", "-SIGRTMIN+16", "-f", "dwmbar.sh", NULL };

static const char *termcmd[] = { "st", NULL };
static const char *browsercmd[] = { "brave", "--password-store=basic", NULL };
static const char *screenshot[] = { "flameshot", "gui", NULL };
static const char *kdeconnectcmd[] = { "kdeconnect-app", NULL };

#define UTILS "/home/chief/.config/scripts/utilities.sh"
static const char *upvol[] = { UTILS, "--upvol", NULL };
static const char *downvol[] = { UTILS, "--downvol", NULL };
static const char *mutevol[] = { UTILS, "--mutevol", NULL };

static const char *light_up[] = { UTILS, "--uplight", NULL };
static const char *light_down[] = { UTILS, "--downlight", NULL };

static const char *connectbluecmd[] = { UTILS, "--connectblue", NULL };
static const char *bluebatcmd[] = { UTILS, "--checkbat", NULL };

static const char *emojiscmd[] = { UTILS, "--emojis", NULL };
static const char *clipboardcmd[] = { UTILS, "--clipboard", NULL };

static const char *weathercmd[] = { UTILS, "--weather", NULL };
static const char *clockcmd[] = { UTILS, "--clock", NULL };
static const char *neofetchcmd[] = { UTILS, "--neofetch", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_t,      spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_k,      spawn,          {.v = kdeconnectcmd } },
	{ MODKEY|ShiftMask,             XK_t,      togglebar,      {0} },
	{ MODKEY,                       XK_Right,  focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Left,   focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,  setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Left,   setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_w,      killclient,     {0} },
	{ MODKEY,                       XK_z,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_c,      centerfloating, {0} },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = powermenucmd } },
	{ MODKEY|ShiftMask,             XK_r,      spawn,          {.v = connectbluecmd } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = bluebatcmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = emojiscmd } },
	{ MODKEY,                       XK_v,      spawn,          {.v = clipboardcmd } },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = weathercmd } },
	{ MODKEY|ShiftMask,             XK_c,      spawn,          {.v = clockcmd } },
	{ MODKEY|ShiftMask,             XK_n,      spawn,          {.v = neofetchcmd } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ 0,              XF86XK_AudioRaiseVolume, spawn,          {.v = upvol } },
	{ 0,              XF86XK_AudioLowerVolume, spawn,          {.v = downvol } },
	{ 0,                     XF86XK_AudioMute, spawn,          {.v = mutevol } },
	{ 0,               XF86XK_MonBrightnessUp, spawn,          {.v = light_up } },
	{ 0,             XF86XK_MonBrightnessDown, spawn,          {.v = light_down } },
	{ 0,                             XK_Print, spawn,          {.v = screenshot } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

