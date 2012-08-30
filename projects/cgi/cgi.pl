#!/usr/bin/perl
print "Content-type: text/html\n\n";

print "<html><body><h2>Lush CGI Test.</h2><hr/>\n";
(let ((query-string (getenv "QUERY_STRING")))
 (printf "QUERY_STRING=%s" query-string))




