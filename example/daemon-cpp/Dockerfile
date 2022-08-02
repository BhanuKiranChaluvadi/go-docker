FROM i386/alpine:3.10 as builder
LABEL description="Build container"

RUN apk update && apk add --no-cache \
    build-base \
    cmake \
    curl \
    git \
    cpputest \
    cunit-dev \
    doxygen

RUN apk add --no-cache \
    xmlrpc-c-dev \
    curl-dev

# Copy source files
COPY hello-world/ /usr/local/src/hello-world/

# Specify the working directory
WORKDIR /usr/local/src/hello-world/build

# Compile daemon
RUN cmake .. && make

FROM i386/alpine:3.10 as runtime
LABEL description="Run container"

# Update apps on the base image
RUN apk update && apk add --no-cache \
    tini \
    libstdc++ \
    xmlrpc-c++ 
    
RUN mkdir /usr/local/daemon
COPY --from=builder /usr/local/src/hello-world/build/HelloWorld /usr/local/daemon/HelloWorld
WORKDIR /usr/local/daemon

ENTRYPOINT ["/sbin/tini", "-v", "--"]
CMD ["./HelloWorld"]

EXPOSE 40405
