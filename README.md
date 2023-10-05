# Ultraviolet MVC

An MVC Web Framework in C++

**Note: This project is in development infancy**

## Components
### CGI Core

The CGI core is functionality that handles low-level components of a CGI (Common Gateway Interface) system, HTTP functionality and basic web application features.
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

Checkout the files and run the script `build`. This will create an index.cgi file which should be placed into the folder `web`, which is the apache webroot.

Note that the .htaccess file in the web directory should have the following directive:
```
Options +ExecCGI
AddHandler cgi-script .cgi
```

Currently this script in bin/index.cpp shows an example of how to set up the environment, set cookies, store sessions, etc. but doesn't really do a whole lot as far as the framework goes. Eventually we plan to have a router so that all the application code will be handled through index.cgi.
