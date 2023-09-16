cd /etc/ssl/private
openssl genrsa -out client.key
openssl req -new -key client.key -out client.csr  # Fill in anything... It doesn't matter
openssl x509 -req -in client.csr -CA rootCA.crt -CAkey rootCA.key -CAcreateserial -days 5 -out client.crt
curl --cert client.crt --key client.key https://connect-me.hitcon2022.online