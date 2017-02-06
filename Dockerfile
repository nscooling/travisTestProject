FROM gcc:latest
RUN apt-get update -y
RUN apt-get install cmake git -y
WORKDIR /usr/feabhas
RUN git clone https://github.com/nscooling/travisTestProject.git; \
    cd travisTestProject; \
    git fetch && git checkout docker; \
    mkdir build; \
    cd build; \
    cmake ../; \
    make; \
    make test
