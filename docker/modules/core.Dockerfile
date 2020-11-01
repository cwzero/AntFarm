FROM liquidforte/ant_farm/builder:latest as builder
WORKDIR /app/build
RUN cmake ..
RUN make core

FROM liquidforte/ant_farm/runner:latest
COPY --from=builder /app/build/core/libcore.so /app/lib/