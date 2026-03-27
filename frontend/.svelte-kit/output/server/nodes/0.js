

export const index = 0;
let component_cache;
export const component = async () => component_cache ??= (await import('../entries/pages/_layout.svelte.js')).default;
export const imports = ["_app/immutable/nodes/0.DSYkXmRX.js","_app/immutable/chunks/CmZm-Iu7.js","_app/immutable/chunks/DOyir5dO.js","_app/immutable/chunks/bz2wIsNM.js"];
export const stylesheets = [];
export const fonts = [];
