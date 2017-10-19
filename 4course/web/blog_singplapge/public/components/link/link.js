import Block from "../block/block.js";


export  default class Link extends Block {
  constructor(options) {
    super('a', options);
    this._el.classList.add(this._options.class || '');
    this.setAttrs(options.attrs);
    this._el.innerText = this._options.attrs.text || 'Press me';
  }
}