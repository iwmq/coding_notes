Generate ERD Diagrams From Django Models 
----
Entity Relationship Diagram (ERD) is an intuitive visualization tool to known
database tables and their relationships. In Django, models are used to define
tables. TO generate ERD from Django models, we can use `django-extensions`.

First install this package and its graphviz:
```
    pip install django-extensions
    sudo apt-get install django-extensions
```

And add `django_extensions` to a project's installed apps.

The run the following command to generate a PDF file for ERD of one or more apps.
```
    python manage.py graph_models app_name | dot -Tpdf > ~/app_name.pdf
```