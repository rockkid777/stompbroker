#!/usr/bin/env node

const Stomp = require('stompjs');

const N = 35;
const socks = [];
for (let j = 0; j < N; j++) {
  // create N websocket connections
  const sock = Stomp.overWS('ws://localhost:3490');
  socks.push(sock);
}

socks.forEach(sock => {
  sock.connect(
      [], () => { setTimeout(() => sock.disconnect(), 10000); }, console.error);
});