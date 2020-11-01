FROM liquidforte/ant_farm/builder:latest as builder
WORKDIR /app/build
RUN cmake ..
RUN make generation

FROM liquidforte/ant_farm/runner:latest
COPY --from=builder /app/build/core/libcore.so /app/lib/
COPY --from=builder /app/build/generation/generation /app/bin/
CMD ["bin/generation"]