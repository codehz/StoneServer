FROM codehz/stonebuilder as builder
ADD . /data
WORKDIR /data
RUN mkdir -p build && \
  cd build && \
  cmake .. && \
  make
RUN mkdir -p output/{usr/lib32,lib,run} && \
  cd output && \
  cat ../lib32.txt | xargs -I {} cp -Lrv /usr/lib32/{} usr/lib32/{} && \
  cp -Lv /usr/lib32/ld-linux.so.2 lib && \
  cp -v {../build/stone/stone,/usr/bin/proot} run

FROM scratch
COPY --from=builder /data/output /
VOLUME ["/run/game", "/run/data","/dbus"]
WORKDIR /run
CMD ["/run/stone"]