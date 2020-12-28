import os
import numpy as np
import tensorflow as tf

print("Tensorflow Version : ", tf.__version__)


def get_model():
    """Create simple convolutional model for mnist.
    """
    
    model = tf.keras.Sequential([
        tf.keras.layers.Conv2D(filters=32, strides=1, kernel_size=(4,4), input_shape=(28,28,1)),
        tf.keras.layers.Activation('relu'),
        tf.keras.layers.BatchNormalization(),
        tf.keras.layers.Flatten(),
        tf.keras.layers.Dense(10)
    ])

    return model



def train_model():
    """Instantiante model, create dataset and train network.
    """

    model = get_model()
    optimizer = tf.keras.optimizers.RMSprop(learning_rate=0.001,momentum=0.9,rho=0.9)
    loss = tf.keras.losses.CategoricalCrossentropy(from_logits=True)
    model.compile(optimizer=optimizer, loss=loss, metrics=['acc'])

    (X_train, Y_train), (X_test, Y_test) = tf.keras.datasets.mnist.load_data()
    X_train = np.expand_dims(X_train, 3)
    X_test = np.expand_dims(X_test, 3)

    # Convert to one-hot vector
    Y_train  = np.eye(10)[Y_train]
    Y_test  = np.eye(10)[Y_test]

    checkpoint_path = "checkpoint/epoch-{epoch:02d}.ckpt"

    cp_callback = tf.keras.callbacks.ModelCheckpoint(filepath=checkpoint_path, verbose=1)

    model.fit(
        X_train,
        Y_train,
        batch_size=32,
        epochs=7,
        callbacks=cp_callback,
        validation_data = (X_test, Y_test),
        verbose=1
    )


if __name__ == "__main__":
    train_model()
