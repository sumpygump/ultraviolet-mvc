# Ultraviolet MVC

An MVC Web Framework in C++

**Note: This project is in development infancy**

## Components

### CGI Core

The CGI core is functionality that handles low-level components of a CGI
(Common Gateway Interface) system, HTTP functionality and basic web application
features.

  * Headers
  * Environment
  * Get Request method parsing
  * Post Request method parsing
  * File Uploads
  * Cookies
  * Sessions

### View Layer

The view layer will be handled as nested partials with token replacement.

### Framework Proper

  * Controllers
  * Models
  * Views

## Installation and Usage

This project uses CMake to generate the Makefile for building.

Run the script `configure.sh` to run the cmake command to generate the Makefile
in `build` subdirectory.

Then run the script `build.sh` to build the project. It will create an
executable `build/index` which will get moved to `web/index.cgi`. The `web`
directory is the root for the web server.

Currently this script in bin/index.cpp shows an example of how to set up the
environment, set cookies, store sessions, etc. but doesn't really do a whole
lot as far as the framework goes. Eventually we plan to have a router so that
all the application code will be handled through index.cgi.

### Install on Nginx

Make sure you install fcgiwrap. Can install on debian based linux machines with:

```
apt -y install fcgiwrap
```

Edit file `/etc/nginx/fcgiwrap.conf`. Add something like this to it:
```
location /cgi-bin/ {
    gzip off;
    fastcgi_pass  unix:/var/run/fcgiwrap.socket;
    include /etc/nginx/fastcgi_params;
    fastcgi_param SCRIPT_FILENAME  $document_root$fastcgi_script_name;
}
```

Then add an include into [server] section of a site definition, e.g.
`/etc/nginx/sites-available/default`

```
server {
    ...
    ...
    include fcgiwrap.conf;
}
```

Enable fcgiwrap with `systemctl enable fcgiwrap`

Restart nginx with `systemctl reload nginx`

Make sure the nginx server root is pointed to the `web` directory in the
ultraviolet directory, or else move the `web` directory to a path served by
nginx. In a browser you should be able to go to the configured website at
`index.cgi` and see the contents rendered by ultraviolet.

### Install on Apache

Note that the .htaccess file in the web directory should have the following directive:

```
Options +ExecCGI
AddHandler cgi-script .cgi
```