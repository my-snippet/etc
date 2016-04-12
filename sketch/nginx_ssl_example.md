in /usr/local/nginx/conf/nginx.conf
```
    server {
        listen       80;
        server_name  wikibootup.com www.wikibootup.com;
        return 301 https://$server_name$request_uri;
    }

    # HTTPS server


    server {
        listen       443 ssl;
        server_name  wikibootup.com www.wikibootup.com;


        ssl_certificate      /etc/letsencrypt/live/wikibootup.com/fullchain.pem;
        ssl_certificate_key  /etc/letsencrypt/live/wikibootup.com/privkey.pem;


        ssl_protocols TLSv1 TLSv1.1 TLSv1.2;
        ssl_prefer_server_ciphers on;

        # dhparam은 보안을 좀 더 강화한다고 하는데, 더 공부
        ssl_dhparam /etc/ssl/certs/dhparam.pem;


        ssl_session_timeout 5m;
        ssl_session_cache shared:SSL:1m;
        ssl_stapling on;
        ssl_stapling_verify on;
        add_header Strict-Transport-Security max-age=15768000;
        ssl_ciphers  HIGH:!aNULL:!MD5;


        location / {
            root   /$PROJECT_ROOT;
            index  index.html index.htm;
        }
    }
```
