#ifndef LSTM_LAYER_H
#define LSTM_LAYER_H

#include "activations.h"
#include "layer.h"
#include "network.h"
#define USET

#ifdef __cplusplus
extern "C"
{
#endif

  layer make_lstm_layer(int batch,
                        int inputs,
                        int outputs,
                        int steps,
                        int batch_normalize,
                        int adam);

  void forward_lstm_layer(layer l, network net);
  void update_lstm_layer(layer l, update_args a);

#ifdef DKGPU
  void forward_lstm_layer_gpu(layer l, network net);
  void backward_lstm_layer_gpu(layer l, network net);
  void update_lstm_layer_gpu(layer l, update_args a);

#endif
#ifdef __cplusplus
}
#endif
#endif
