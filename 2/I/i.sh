#!/usr/bin/env bash
chmod +x I.py
perl -e 'open F, ">", "/tmp/orig"; print F "1\n"; print F int 2 * rand for 1..100000; close F'
echo '2' > /tmp/encoded
echo '1' > /tmp/decoded
echo 'Encoding:'
time python3 I.py < /tmp/orig >> /tmp/encoded
read
echo 'Decoding:'
time python3 I.py < /tmp/encoded >> /tmp/decoded
diff -Z -q /tmp/orig /tmp/decoded
