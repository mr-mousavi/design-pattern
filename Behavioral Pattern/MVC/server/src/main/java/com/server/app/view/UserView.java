package com.server.app.view;

import org.microdeaf.common.view.BaseView;
import lombok.Data;

@Data
public class UserView extends BaseView<Long> {

    private String name;
    private String username;
    private String authKey;
    private String password;
    private Integer status;

}
