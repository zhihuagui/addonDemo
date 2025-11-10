
const addon = require('./build/Release/myAddon.node');

const callResult = addon.CallRegex('GUID(1230, 9542352)');

console.log(`addon ${callResult}`);
