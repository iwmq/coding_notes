FROM python:3.10-alpine

RUN pip install redis flask

ADD ./code /code
WORKDIR /code

CMD ["python", "app.py"]