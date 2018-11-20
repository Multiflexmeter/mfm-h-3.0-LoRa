pipeline {
  agent any
  stages {
    stage('Test native') {
      steps {
        withCredentials([string(credentialsId: 'PIO_AUTH', variable: 'PIO_AUTH')]) {
          sh 'set -x && PLATFORMIO_AUTH_TOKEN=$PIO_AUTH pio test -e native'
        }
      }
    }
    stage('Test UNO') {
      steps {
        withCredentials([string(credentialsId: 'PIO_AUTH', variable: 'PIO_AUTH')]) {
          sh 'set -x && PLATFORMIO_AUTH_TOKEN=$PIO_AUTH pio remote --agent multiflexmeter-desktop test -e uno'
        }
      }
    }
  }
}
