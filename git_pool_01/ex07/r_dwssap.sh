FT_LINE1=5
FT_LINE2=10
cat /etc/passwd | grep -v '^#' | sed -n '2~2p' | cut -d: -f1 | rev | sort -r | awk -v start=$FT_LINE1 -v end=$FT_LINE2 'NR>=start && NR<=end' | paste -sd, - | sed 's/,/, /g' | sed 's/$/./'

