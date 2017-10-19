import Block from "../block/block"

export default class Post extends Block {
    constructor(options = {
        data: {}
    }) {
        super('div');
        this.data = options.data;
        this.template = window.fest["post/post.tmpl"];

        this.render();
    }

    /**
     * Обновляем HTML
     */
    render() {
        this._updateHtml();
    }

    /**
     * Обновить html компонента
     */
    _updateHtml() {
        this._el.innerHTML = this.template(this.data);
    }
}