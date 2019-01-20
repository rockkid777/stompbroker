FROM gcc:latest as builder

WORKDIR /root
ADD . /root
RUN ./build.sh

FROM alpine:latest

ARG appdir=/app
WORKDIR ${appdir}
RUN ["ls", "-la"]
COPY --from=builder /root/stompbroker.out ${appdir}
EXPOSE 3490

CMD ./stompbroker.out
