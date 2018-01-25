FROM devcomb/eos-builder as builder
COPY tests /eos/tests
COPY eos-contracts /eos/contracts
RUN /eos/contracts/create_contracts.sh

FROM devcomb/eos
COPY --from=builder /eos/contracts /contracts
