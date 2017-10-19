import Block from "../block/block.js";


export  default class Button extends Block {
  constructor(options) {
    super('button', options);
    //this._el.classList.add('button');
    this._el.classList.add(this._options.class || '');
    this._el.innerText = this._options.text || 'Press me';
  }
}



