package com.server.app.view;

import lombok.Data;
import org.microdeaf.common.view.BaseView;

import java.io.Serializable;

@Data
public abstract class BaseIruIfsoView<PK extends Serializable> extends BaseView<PK> {


}
