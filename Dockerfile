FROM gcc:8.2 as builder
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN g++ -o myapp an.cpp


CMD ["./an"]