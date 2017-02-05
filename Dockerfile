FROM gcc:latest
RUN apt-get update -y
RUN apt-get install cmake git -y
WORKDIR /usr/src/myapp
RUN git clone https://github.com/nscooling/travisTestProject.git; \
    cd travisTestProject; \
    mkdir build; \
    cd build; \
    cmake ../; \
    make; \
    make test
CMD ["/usr/src/myapp/travisTestProject/build/testProject"]
