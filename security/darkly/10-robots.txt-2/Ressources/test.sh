wget \
     --quiet\
     -H\
     --recursive \
     --no-clobber \
     --domains 192.168.56.101 \
     -e robots=off\
     --no-parent \
         192.168.56.101/.hidden/
