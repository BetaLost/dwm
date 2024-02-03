# dwm 6.4
**Patches**
* [Full Gaps](https://dwm.suckless.org/patches/fullgaps/)
* [Fancy Bar](https://dwm.suckless.org/patches/fancybar/)
* [Center](https://dwm.suckless.org/patches/center/)
* [Underline Tags](https://dwm.suckless.org/patches/underlinetags/)
* [Status2d](https://dwm.suckless.org/patches/status2d/)
* [Status Padding](https://github.com/BetaLost/dwm/commit/42839e104b0b2408b29f04a83a2b1489f93b271d) - Reference: [ChadWM](https://github.com/siduck/chadwm)
* [Bar Padding](https://github.com/BetaLost/dwm/commit/c4e325d27afee974f5bfd06fb3ce03d06e22efe2) - There are 2 known issues caused by this patch: 
  * The status bar does not account for the new width of the bar which means horizontal status padding is broken
  * The client name text is no longer cropped when there is no space, it just starts again
* [Display WM_CLASS instead of _NET_WM_NAME in `dwm.c`](https://www.reddit.com/r/dwm/comments/ssm1ph/how_to_make_it_so_that_the_window_title_only/) - References: [1652](https://github.com/BetaLost/dwm/blob/f452d3ea748492e43054e3c43639894b394dd178/dwm.c#L1652) & [2084](https://github.com/BetaLost/dwm/blob/f452d3ea748492e43054e3c43639894b394dd178/dwm.c#L2084)
* [Changed rate of movemouse (60->144) and resizemouse (60->288) in `dwm.c`](https://www.reddit.com/r/suckless/comments/tlxaqr/comment/i2ovsb1/) - References: [movemouse](https://github.com/BetaLost/dwm/blob/f452d3ea748492e43054e3c43639894b394dd178/dwm.c#L1242) & [resizemouse](https://github.com/BetaLost/dwm/blob/f452d3ea748492e43054e3c43639894b394dd178/dwm.c#L1396)
* [Added a function in `dwm.c` to center a floating window](https://github.com/BetaLost/dwm/blob/2ede06ded3f8d5a3b74c7ff671f4e81d21977ef1/dwm.c#L2212-L2227) - [Reddit Post](https://www.reddit.com/r/suckless/comments/cphe3h/comment/ewqnx65/)
* [Modified `drawbar` function in `dwm.c` to set different color schemes depending on tag status](https://github.com/BetaLost/dwm/blob/2ede06ded3f8d5a3b74c7ff671f4e81d21977ef1/dwm.c#L761) - [Reddit Post](https://www.reddit.com/r/suckless/comments/o9fqci/comment/h3c6jhr/)
* [Modified `drawbar` function in `dwm.c` to underline selected client](https://github.com/BetaLost/dwm/blob/2ede06ded3f8d5a3b74c7ff671f4e81d21977ef1/dwm.c#L802-L803)
* [Modified `drawbar` function in `dwm.c` to shorten client name text for certain programs](https://github.com/BetaLost/dwm/blob/36eaae22087e6352c7942e2a03ad0530010dd2df/dwm.c#L880-L884)
* ~~[Modified `drawbar` function in `dwm.c` to set a color scheme for inactive tags](https://gitlab.com/d1str0l3ss/d1str0l3ss-dwm/-/blob/master/dwm.c?ref_type=heads#L579-L587) - [Reddit Post](https://www.reddit.com/r/unixporn/comments/13af8z1/comment/jj7cxeo/)~~

**Hotkeys**
* *Super + r:* Spawn dmenu (search)
* *Super + t:* Spawn st (terminal)
* *Super + b:* Spawn brave (browser)
* *Super + w:* Close window (killclient)
* *Super + Shift + t:* Toggle Bar
* *Super + Minus:* Reduce gaps
* *Super + Equal:* Increase gaps
* *Super + Shift + Equal:* Remove gaps
* *Super + q:* Quit dwm
* *Super + 1-5:* Switch to workspace
* *Super + Shift + 1-5:* Send focused window to workspace
* *Super + Right Arrow:* Focus next window
* *Super + Left Arrow:* Focus previous window
* *Super + Shift + Right Arrow:* Increase master area size
* *Super + Shift + Left Arrow:* Decrease master area size
* *Super + i:* Increase number of master windows
* *Super + d:* Decrease number of master windows
* *Super + Return:* Cycle focused window to/from master area
* *Super + Tab:* Switch to previously selected workspace
* *Super + Space:* Toggle floating mode for current window
* *Super + c:* Center a floating window
* *Super + z:* Set tiling mode []=
* *Super + f:* Set floating mode ><>
* *Super + m:* Set monocle mode [M]
* *Super + Comma:* Focus previous monitor
* *Super + Period:* Focus next monitor
* *Super + Shift + Comma:* Send focused window to previous monitor
* *Super + Shift + Period:* Send focused window to next monitor
* *Super + 0:* View all windows regardless of tag
* *Super + Shift + 0:* Send focused window to all workspaces (apply all tags)
* *Print screen:* Spawn flameshot (screenshot)
* *Super + Shift + f:* Display weather information in a floating st window (runs utilities.sh)
* *Super + Shift + c:* Display clock in a floating st window (runs utilities.sh)
* *Super + Shift + n:* Display neofetch in a floating st window (runs utilities.sh)
* *Audio keys:* Increase/decrease/mute volume (runs utilities.sh)
* *Brightness keys:* Increase/decrease brightness (runs utilities.sh)
