#pragma once
#include <draw_lines.h>
void DrawLine(uLinePoints& m, QGraphicsScene* scene)
{
    scene->addLine(m.x1, m.y1, m.x2, m.y2);
    return;
}
uLinePoints get_line_info(int i )
{
    uLinePoints m;
    m.x1 = converted->Xs[mdl.links[i]];
    m.y1 = converted->Ys[mdl.links[i]];
    m.x2 = converted->Xs[mdl.links[i + 1]];
    m.y2 = converted->Ys[mdl.links[i + 1]];
    return m;
}

void DrawEdges(sConvertedPoints* converted, uChangeData data, sModel& mdl)
{
    for (int i = 0; i < mdl.edge_num; i += 2) {
        uLinePoints tt = get_line_info(i);
        DrawLine(tt, data.scene);
    }
    return;
}

void ClearScene(QGraphicsScene* dt) { dt->clear(); }
