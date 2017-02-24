FROM gcc:latest
RUN apt-get update -y
RUN apt-get install cmake git -y
WORKDIR /usr/feabhas
ADD * /usr/feabhas/
RUN mkdir build; \
    cd build; \
    cmake ../; \
    make 
