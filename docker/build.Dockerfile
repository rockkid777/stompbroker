FROM gcc
ENV wd /root
WORKDIR ${wd}
ADD . ${wd}
EXPOSE 3490
RUN ./build.sh
