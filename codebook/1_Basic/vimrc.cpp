se nu rnu ai hls et ru ic is sc cul
se re=1 ts=4 sts=4 sw=4 ls=2 mouse=a
syntax on
hi cursorlinenr cterm=bold
hi cursorline cterm=none ctermbg=237
hi normal ctermbg=235
set bg=dark
ino {<CR> {<CR>}<Esc>ko<tab>
xn gc :s/^/\/\/ /<CR>:noh<CR>
xn gu :s/^\/\/\s\?//<CR>:noh<CR>
nn gc :s/^/\/\/ /<CR>:noh<CR>
nn gu :s/^\/\/\s\?//<CR>:noh<CR>
gsettings set org.gnome.desktop.input-sources xkb-options "['caps:escape']"