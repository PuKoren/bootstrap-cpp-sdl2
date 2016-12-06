FROM alpine:edge

RUN apk add --no-cache sdl2-dev sdl2_image-dev sdl2_ttf-dev cppunit-dev cmake make gcc build-base && \
  rm -rf /var/cache/apk/*

WORKDIR project

VOLUME /project